<?php
    // configuration
    require("../includes/config.php"); 
    // get portfolios data for user
    $rows = CS50::query("SELECT symbol, shares FROM portfolios WHERE user_id = ?", $_SESSION["id"]);
    // get users data for user
    $users = CS50::query("SELECT * FROM users WHERE id = ?", $_SESSION["id"]);
    // construct array
    $positions = [];
    // store into positions
    foreach($rows as $row)
    {
        // lookup stock
        $stock = lookup($row["symbol"]);
        // check lookup handed back data
        if ($stock !== false)
        {
            // then store into aray
            $positions[] = [
                "symbol" => $row["symbol"],
                "name" => $stock["name"],
                "shares" => $row["shares"],
                "price" => $stock["price"],
                "Total" => $row["shares"] * $stock["price"],            
            ];
        }
    }
    // render portfolio
    render("portfolio.php", ["title" => "Portfolio", "positions" => $positions, "users" => $users]);
?>
