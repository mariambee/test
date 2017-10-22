<?php
    // configuration
    require("../includes/config.php");
    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("register_form.php", ["title" => "Register"]);
    }
    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // check that username field is not empty
        if (empty($_POST["username"]))
        {
            apologize("Pls enter a username.");
        }
        // check that password field is not empty
        if (empty($_POST["password"]))
        {
         apologize("Pls enter a password.");
        }
        // check that confirmation field is not empty
        if (empty($_POST["confirmation"]))
        {
            apologize("Pls confirm your password.");
        }
        // check that the password and the confirmation are equal
        if ($_POST["confirmation"] != $_POST["password"])
        {
            apologize("Oops, you entered two different passwords.");
        }
        // check if user already exists
        $rows = CS50::query("SELECT * FROM users WHERE username = ?", $_POST["username"]);
        if(count($rows) == 1)
        {
            apologize("You already registered! Go log in!");
        }
        // else register user
        else 
        {
            $result = CS50::query("INSERT IGNORE INTO users (username, hash, cash) 
            VALUES(?, ?, 10000.0000)", $_POST["username"], password_hash($_POST["password"], PASSWORD_DEFAULT));
            // check for successful insert
            if ($result=== false)
            {
                apologize("Sorry, registration unsuccessful");
            }
            else 
            {
                // keep user logged in
                $rows = CS50::query("SELECT LAST_INSERT_ID() AS id");
                $id = $rows[0]["id"];
                $_SESSION["id"] = $id;
                redirect("/index.php");
            }
        }
    }

?>