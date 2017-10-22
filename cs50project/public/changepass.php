<?php
    // configuration
    require("../includes/config.php");
    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        render("changepass_form.php", ["title" => "Change Password"]);
    }
    // if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // check for empty fields and respond
        if (empty($_POST["oldpassword"]))
        {
            apologize("Please fill in oldpasswprd.");
        }
        if (empty($_POST["newpassword"]))
        {
            apologize("Please fill in newpassword.");
        }
        if (empty($_POST["confirmation"]))
        {
            apologize("Please confrim newpassword.");
        }
        // check new password and confrimation match
        if ($_POST["newpassword"] != $_POST["confirmation"])
        {
            apologize("New passwpprd and confirmation do not match.");
        }
        // query table
        $hash = CS50::query("SELECT hash FROM users WHERE id = ?",
            $_SESSION["id"]);
        // verify oldpassword with the correct password
        if (password_verify($_POST["oldpassword"], $hash[0]["hash"]))
        {
            // change password
            $changepass = CS50::query("UPDATE users SET hash = ? WHERE 
                id = ? ", password_hash($_POST["newpassword"], PASSWORD_DEFAULT), 
                $_SESSION["id"]);
            // check return
            if ($changepass == false)
                {
                    apologize("Sorry, error changing your password.");
                }
            else
            {
                redirect("/index.php");
            }
        }
        else
        {
            apologize("Sorry, wrong password.");
        }
    }
?>