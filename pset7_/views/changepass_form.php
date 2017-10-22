<form action="changepass.php" method="post">
    <fieldset>
        <!-- print username -->
        <div>
            <h2>
                Hello, 
                <?php 
                    $name = CS50::query("SELECT username FROM users 
                    WHERE id = ?", $_SESSION["id"]);
                    print("{$name['0']['username']}");
                ?>
            </h2>
        </div>
        <!-- create oldpassword field -->
        <div class="form-group">
            <input class="form-control" name="oldpassword" 
            placeholder="Old Password" type="password"/>
        </div>
        <!-- creat newpassword field -->
        <div class="form-group">
            <input class="form-control" name="newpassword" 
            placeholder="New Password" type="password"/>
        </div>
        <!-- create confirmation field -->
        <div class="form-group">
            <input class="form-control" name="confirmation" 
            placeholder="Confirm password" type="password"/>
        </div>
        <!-- create button -->
        <div class="form-group">
            <button class="btn btn-default" type="submit">
                <span aria-hidden="true" class="glyphicon glyphicon-log-in"></span>
                Change Password
            </button>
        </div>
    </fieldset>
</form>