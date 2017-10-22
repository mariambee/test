<?php
    // configuration
    require("../includes/config.php"); 
    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // get history data for user
        $rows = CS50::query("SELECT * FROM history WHERE user_id = ?", $_SESSION["id"]);
        // construct array
        $positions = [];
        // store into positions
        foreach($rows as $row)
        {
            // set the value of the positions
            $positions[] = [
                "sourcetext" => $row["sourcetext"],
                "from_lang" => $row["from_lang"],
                "to_lang" => $row["to_lang"],
                "google" => $row["google"],
                "microsoft" => $row["microsoft"],
            ];
        }
        // render history view
        render("history_form.php", ["title" => "History", "positions" => $positions]);
    }
    // else the page is reached via POST
    else if ($_SERVER["REQUEST_METHOD"] == "POST") 
    {
        // cs50 query call to insert the CS50 Translators call to the history databse
        $history = CS50::query("INSERT INTO history(user_id, sourcetext, from_lang, to_lang, google, microsoft) VALUES (?, ?, ?, ?, ?, ?)", 
            $_SESSION["id"], $_POST["sourcetext"], $_POST["from_lang"], $_POST["to_lang"], $_POST["google"], $_POST["microsoft"]);
    }
?>
