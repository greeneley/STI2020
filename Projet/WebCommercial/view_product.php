<?php
session_start();
include_once("config.php");
?>
<html>
<header>
<link href="style.css" rel="stylesheet">
<link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.1.1/css/bootstrap.min.css" integrity="sha384-WskhaSGFgHYWDcbwN70/dfYBj47jz9qbsMId/iRN3ewGhXQFZCSftd1LZCfmhktB" crossorigin="anonymous">
<script src="https://stackpath.bootstrapcdn.com/bootstrap/4.1.1/js/bootstrap.min.js" integrity="sha384-smHYKdLADwkXOn1EmN1qk/HfnUcbVRZyYmZ4qpPea6sjB/pTJ0euyQp0Mk8ck+5T" crossorigin="anonymous"></script>
<!-- Bootstrap-->
<link href="http://netdna.bootstrapcdn.com/twitter-bootstrap/2.3.1/css/bootstrap-combined.min.css" rel="stylesheet" type="text/css"/>
<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js"></script>
<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
</header>

<body>
<div class="container-fluid">
        <div class="row-fluid">
            <div class="span10 offset1">
                <h1 class="well" >
                    <a href="index.php">
                        <img src="img/logo.jpg" height="80" width="100" alt="logo"/>
                    </a>
                    Fruit Store                                     
                    <img src=img/insa.png align="right" >
                </h1>
                <div ng-view></div>
            </div>
        </div>
</div>
<div class="container"><h1> DETAIL PRODUCT</h1>
<div id="products-wrapper">
<div class="view-cart">
<?php 
       $current_url = base64_encode($_SERVER['REQUEST_URI']);
       $product_id = $_GET['product'];
       $results = $mysqli->query("SELECT name, description, price, property FROM product WHERE product_id ='$product_id' LIMIT 1");
       $obj = $results->fetch_object();
       echo '<table class="table table-bordered table-responsive table-striped">';
       echo '<form method="post" action="PAYMENT-GATEWAY">';
       echo '<tr>';   
       echo '<th>Name</th>';
       echo '<th>Price</th>';
       echo '<th>Description</th>';
       echo '</tr>';
       echo '<tr>';
       echo '<td>'.$obj->name.'</td>';
       echo '<td>'.$obj->price.'</td>';
       echo '<td>'.$obj->description.'</td>';
       echo '</tr>';
       echo '</form>';
       echo '</table>';
?>
</div>
</div>
</div>
</body>
<footer class="footer">
        <div>© DINH Thanh Hai - TRAN Duc Minh - KATAPI Baptista - BOUCHAMMACH Sofian - 3A STI INSA CVL</div>
</footer>
</html>