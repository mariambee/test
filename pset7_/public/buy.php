<?php
    // configuration
    require("../includes/config.php");
    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        render("buy_form.php", ["title" => "Buy"]);
    }
    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // check conditions for fields
        if (empty($_POST["symbol"]))
        {
            apologize("Please enter a stock symbol.");
        }
        if (empty($_POST["shares"]) || !preg_match("/^\d+$/", $_POST["shares"]))
        {
            apologize("Please enter a non-negative integer amount of shares.");
        }
        // look up stock
        $stock = lookup($_POST["symbol"]);
        // check return
        if ($stock == false)
        {
            apologize("Please enter a valid stock symbol.");
        }
        // get user cash
        $cash = CS50::query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
        // how much does the request cost
        $buyvalue = $stock["price"] * $_POST["shares"];
        // check if user can afford it
        if ($cash[0]["cash"] < $buyvalue)
        {
            apologize("Sorry, you don't have enough $$$$$.");
        }
        else
        {
            // insert new row
            $buy = CS50::query("INSERT INTO portfolios (user_id, symbol, shares) 
                VALUES(?, ?, ?) ON DUPLICATE KEY UPDATE shares = shares + VALUES(shares)", 
                $_SESSION["id"], strtoupper($stock["symbol"]), $_POST["shares"]);
            // check return
            if ($buy == false)
            {
                apologize("Sorry, error buying shares.");
            }
            // update user cash in data
            $updatecash = CS50::query("UPDATE users SET cash = cash - ? where id = ?", $buyvalue, $_SESSION["id"]);
            // check return
            if ($updatecash == false)
            {
                apologize("Sorry, error updating cash.");
            }
            // update cash
            $cash[0]["cash"] -= $buyvalue;
            // insert into history
            $history = CS50::query("INSERT INTO history(user_id, transaction, 
                date, symbol, shares, price) VALUES (?, 'BUY', NOW(), ?, ?, ?)", 
                $_SESSION["id"], strtoupper($_POST["symbol"]), $_POST["shares"], 
                $stock["price"]);
            redirect("/index.php");
        }
    }
?>