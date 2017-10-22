<!DOCTYPE html>

<html>

    <head>

        <!-- http://getbootstrap.com/ -->
        <link href="/css/bootstrap.min.css" rel="stylesheet"/>

        <link href="/css/styles.css" rel="stylesheet"/>

        <?php if (isset($title)): ?>
            <title>CS50 Translate: <?= htmlspecialchars($title) ?></title>
        <?php else: ?>
            <title>CS50 Translate</title>
        <?php endif ?>

        <!-- https://jquery.com/ -->
        <script src="/js/jquery-1.11.3.min.js"></script>

        <!-- http://getbootstrap.com/ -->
        <script src="/js/bootstrap.min.js"></script>

        <script src="/js/scripts.js"></script>

         <script> var userLang = navigator.language || navigator.userLanguage; </script>

    </head>

    <body>

        <div class="container">

            <div id="top">
                <div>
                    <a href="/"><img alt="CS50 Translate" src="/img/logo.png"/></a>
                </div>
                <?php if (!empty($_SESSION["id"])): ?>
                    <ul class="nav nav-pills">
                        <li><a href="accuracy.php">Accuracy</a></li>
                        <li><a href="history.php">History</a></li>
                        <li><a href="changepass.php">Change Password</a></li>
                        <li><a href="aboutme.php">About Me</a></li>
                        <li><a href="logout.php">Log Out</a></li>
                    </ul>
                <?php endif ?>
            </div>

            <div id="middle">
            
            <!-- date -->
            <span id="spanDate" style= "font-size: 15px; font-weight: bold;"></span><script type="text/javascript">var months = ['January','February','March','April','May','June','July','August','September','October','November','December'];var tomorrow = new Date();tomorrow.setTime(tomorrow.getTime() + (1000*3600*24));document.getElementById("spanDate").innerHTML = months[tomorrow.getMonth()] + " " + tomorrow.getDate()+ ", " + tomorrow.getFullYear();</script> <!-- credit to http://stackoverflow.com/questions/4904667/html-how-do-i-insert-dynamic-date-in-webpage -->
            
            <!-- time -->
            <div id=Clock align=center style="font-family: Verdana; font-weight: bold; font-size: 15px; color:#000000">&nbsp;</div><script language="JavaScript">function tick() {var hours, minutes, seconds, ap;var intHours, intMinutes, intSeconds;var today;today = new Date();intHours = today.getHours();intMinutes = today.getMinutes();intSeconds = today.getSeconds();if (intHours == 0) {hours = "12:";ap = "Midnight";} else if (intHours < 12) {hours = intHours+":";ap = "A.M.";}else if(intHours==12){hours="12:";ap="Noon";}else{intHours=intHours - 12;hours=intHours + ":";ap="P.M.";}if(intMinutes < 10){minutes="0"+intMinutes+":";}else{minutes=intMinutes+":";}if(intSeconds < 10){seconds="0"+intSeconds+" ";}else{seconds=intSeconds+" ";}timeString=hours+minutes+seconds+ap;Clock.innerHTML=timeString;window.setTimeout("tick();",100);}window.onload=tick;</script> <!-- credit to http://www.jsmadeeasy.com/javascripts/IE5%20Scripts/clock/template.htm--> 

            
