<?php
session_start();
include_once("config.php");
?>
<html>
<header>
<link href="style.css" rel="stylesheet"> 
 <!-- Bootstrap-->
 <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.1.1/css/bootstrap.min.css" integrity="sha384-WskhaSGFgHYWDcbwN70/dfYBj47jz9qbsMId/iRN3ewGhXQFZCSftd1LZCfmhktB" crossorigin="anonymous">
<script src="https://stackpath.bootstrapcdn.com/bootstrap/4.1.1/js/bootstrap.min.js" integrity="sha384-smHYKdLADwkXOn1EmN1qk/HfnUcbVRZyYmZ4qpPea6sjB/pTJ0euyQp0Mk8ck+5T" crossorigin="anonymous"></script>

<link href="http://netdna.bootstrapcdn.com/twitter-bootstrap/2.3.1/css/bootstrap-combined.min.css" rel="stylesheet" type="text/css"/>
<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js"></script>
<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>

</header>
<body ng-controller="MyController">
<div class="container-fluid" >
        <div class="row-fluid">
            <div class="span10 offset1">
                <h1 class="well" >
                    <a href="index.php">
                        <img src="img/logo.jpg" height="80" width="100" alt="logo"/>
                    </a>
                    Fruit Store                                     
                   <img src="img/insa.png" height="25%" width="15%" align="right" >
                </h1>
                <div ng-view></div>
            </div>
        </div>
</div>
<div class="container" >
   <center><img src="img/checked.png" align="center">
   <h1>PAYMENT SUCCESSFUL </h1></center>

<?php
if(isset($_SESSION["products"]))
{
    $current_url = base64_encode($_SERVER['REQUEST_URI']);
    echo '<meta http-equiv="refresh" content="0.0001;URL= cart_update.php?emptycart=1&return_url='.$current_url.'">';
}else{
    
    echo '<meta http-equiv="refresh" content="2;URL= index.php">';
}
?>

</div>
</body>
<footer class="footer">
        <div><br><br>© DINH Thanh Hai - TRAN Duc Minh - KATAPI Baptista - BOUCHAMMACH Sofian - 3A STI INSA CVL</div>
</footer>
</html>