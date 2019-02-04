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
    <div class="content">
    <h3> PROJET INGENIEURE DU WEB - 3A STI </h3  >
    <div class="container-fluid">
            <div class="row-fluid">
                <div class="span10 offset1">
                    <h1 class="well" >
                        <a href="index.php">
                            <img src="img/logo.jpg" height="100" width="100" alt="logo"/>
                        </a>
                        Fruit Store                                     
                        <img src="img/insa.png" height="25%" width="15%" align="right" >
                    </h1>
                    <div ng-view></div>
                </div>
            </div>
    </div>  
    <div class="container">
    <div id="products-wrapper">
    <div class="container-fluid">
    <div class="row-fluid">
    <div class="products">
<?php
$current_url = base64_encode($_SERVER['REQUEST_URI']);
    
    $results = $mysqli->query("SELECT * FROM product ORDER BY product_id ASC");
    if ($results) {
        //output results from database
        echo '<div class="product">';
        echo '<table class="table table-bordered table-responsive table-striped">';
        
        echo '<tr>';   
        echo '<th>Name</th>';
        echo '<th>Image</th>';
        echo '<th>Description</th>';
        echo '<th>Prix</th>';
        echo '<th>Quantity</th>';
        echo '<th>Action</th>';
        echo '</tr>';
        while($obj = $results->fetch_object())
        {   

       
        echo '<form method="post" action="cart_update.php">';
        echo '<tr>';
        echo '<td class="product-content"><h4><a href="view_product.php?product='.$obj->product_id.'">'.$obj->name.'</a></h4></td>';
        echo '<td class="product-thumb"><img src="'.$obj->image.'" width="500px"></td>';
               echo '<td class="product-desc">'.$obj->description.'</td>';
               echo '<td class="product-info">'.$currency.$obj->price.'</td>';
               echo '<td><input type="text" size="5" name="product_qty" placeholder="Enter the quantity!"></td>';

               echo '<td><button class="btn btn-primary btn-xs" class="add_to_cart" >Add To Cart  <span class="glyphicon glyphicon-shopping-cart"></span></button></td>';
               
               echo '<input type="hidden" name="product_id" value="'.$obj->product_id.'" />';
               echo '<input type="hidden" name="type" value="add" />';
               echo '<input type="hidden" name="return_url" value="'.$current_url.'" />';
               echo '</tr>';

            echo '</form>';
        } 
        
   
        echo '</table>';
}
?>
</div>
</div>
</div>
 
 <div class="shopping-cart">
<h2>Cart</h2>
<?php
if(isset($_SESSION["products"]))
{
    $total = 0;
    // echo '<ol>';
    $cart_items = 0;
    foreach ($_SESSION["products"] as $cart_itm)
    {
        $subtotal = ($cart_itm["price"]*$cart_itm["qty"]);
        $cart_items ++;
        $total = ($total + $subtotal);
    }
    // echo '</ol>';
    echo '</form>';
    echo '</table>';
    echo '<span class="check-out-txt"><strong>'.$cart_items.' Items, Total: '.$currency.$total.' </strong><pre> <a class="btn btn-success" href="view_cart.php"><span class="glyphicon glyphicon-shopping-cart"></span> View Cart!</a> </span>';
}else{
    echo 'Empty Cart';
}
?>


</div>
</div>
</div>

<footer class="footer">
        <div>© DINH Thanh Hai - TRAN Duc Minh - KATAPI Baptista - BOUCHAMMACH Sofian - 3A STI INSA CVL</div>
</footer>
<div>
</body>
</html>