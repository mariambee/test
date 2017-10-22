<?php
    // configuration
    require("../includes/config.php"); 
    // check if user reached page via POST
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // lookup stock
        $stock = lookup($_POST["symbol"]);
        // check input and then render
        if ($stock === false)
        {
            apologize("Invalid stock symbol");
        }
        else
        {
             render("quote.php", ["title" => "Quote", "stock" => $stock]);
        }
    }
    // else reached page via GET
    else
    {
         render("quote_form.php", ["title" => "Quote"]);
    }
?>