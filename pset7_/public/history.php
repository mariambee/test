<?php
    // configuration
    require("../includes/config.php"); 
    // get history data for user
    $rows = CS50::query("SELECT * FROM history WHERE user_id = ?", $_SESSION["id"]);
    // construct array
    $positions = [];
    // store into positions
    foreach($rows as $row)
    {
        $positions[] = [
            "transaction" => $row["transaction"],
            "date" => $row["date"],
            "symbol" => $row["symbol"],
            "shares" => $row["shares"],
            "price" => $row["price"],
        ];
    }
    // render history
    render("history_form.php", ["title" => "History", "positions" => $positions]);
?>
