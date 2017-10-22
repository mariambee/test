<form action="sell.php" method="post">
    <fieldset>
        <div class="form-group">
            <!-- create drop down menu -->
            <select class="form-control" name="symbol">
                    <?php
                    foreach($symbols as $symbol)
                    {
                        print("<option value='" . $symbol . "'>" . $symbol . "</option>");                    
                    }
                ?>
            </select>
        </div>
        <div class="form-group">
            <!-- create sell button -->
            <button class="btn btn-default" type="submit">Sell</button>
        </div>
    </fieldset>
</form>