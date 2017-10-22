<form action="buy.php" method="post">
    <fieldset>
        <!-- create symbol field -->
        <div class="form-group">
            <input autocomplete="off" autofocus class="form-control" name="symbol" placeholder="Enter stock symbol" type="text"/>
        </div>
        <!-- create number field -->
        <div class="form-group">
            <input autocomplete="off" autofocus class="form-control" name="shares" placeholder="# of shares" type="text"/>
        </div>
        <div class="form-group">
            <!-- create buy button -->
            <button class="btn btn-default" type="submit">Buy</button>
        </div>
</form>
        