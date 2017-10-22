<?php
    // configuration
    require("../includes/config.php");  
    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // get stock
        $rows = CS50::query("SELECT * FROM portfolios WHERE user_id = ?", $_SESSION["id"]);
        // check if there is stock to sell
        if ($rows == false)
        {
            apologize("Nothing to sell.");
        }
        // else render form
        else 
        {
            // create array of symbols
            $symbols = []; 
            // store into array
            foreach($rows as $row)
            {
                $symbol = $row["symbol"];
                $symbols[] = $symbol;
            }
            render("sell_form.php", ["title" => "Sell", "symbols" => $symbols]);
        }
    }
    // if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST") 
    {
        // lookup stock
        $stock = lookup($_POST["symbol"]);
        // check lookup
        if ($stock == false)
        {
            apologize("Sorry, could not find stock.");
        }
        // lookup shares being sold
        $shares = CS50::query("SELECT shares FROM portfolios WHERE user_id = ? 
            AND symbol = ?", $_SESSION["id"], $_POST["symbol"]);
        If ($shares == false)
        {
            apologize("Sorry, could not get shares.");
        }
        // calculate total sale value
        $salevalue = $stock["price"] * $shares[0]["shares"];
        // add total sale value to cash
        CS50::query("UPDATE users SET cash = cash + ? WHERE id = ?", $salevalue, $_SESSION["id"]);
        // delete the stock from user portfolio 
        CS50::query("DELETE FROM portfolios WHERE user_id = ? AND 
            symbol = ?", $_SESSION["id"], $_POST["symbol"]);     
        // insert into history
        $history = CS50::query("INSERT INTO history(user_id, transaction, 
            date, symbol, shares, price) VALUES (?, 'SELL', NOW(), ?, ?, ?)", 
            $_SESSION["id"], strtoupper($_POST["symbol"]), $shares[0]["shares"], 
            $stock["price"]);
        redirect("/index.php");
    }
?>