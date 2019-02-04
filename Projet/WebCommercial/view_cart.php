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
<div class="container" ><h1>VIEW CART</h1>
<div id="products-wrapper">
<div class="view-cart">

<?php
if(isset($_SESSION["products"]))
{
    $current_url = base64_encode($_SERVER['REQUEST_URI']);
    $total = 0;
    // echo '<ol>';
    echo '<table class="table table-bordered table-responsive table-striped">';
    echo '<form method="post" action="cart_update.php">';
    echo '<tr>';   
    echo '<th>Name</th>';
    echo '<th>Quantity</th>';
    echo '<th>Price</th>';
    echo '<th>Action</th>';
    echo '</tr>';
    $cart_items = 0;
    foreach ($_SESSION["products"] as $cart_itm)
    {

        $product_id = $cart_itm["id"];
        $results = $mysqli->query("SELECT name, description, price FROM product WHERE product_id ='$product_id' LIMIT 1");
        $obj = $results->fetch_object();
        $subtotal = ($cart_itm["price"]*$cart_itm["qty"]);
        echo '<tr>';
        echo '<td>'.$cart_itm["name"].'</td>';
        
        echo '<td class="p-qty">'.$cart_itm['qty'].'</td>';
        $subtotal = ($cart_itm["price"]*$cart_itm["qty"]);  
        echo '<td class="p-price">'.$currency.$subtotal.'</td>';
        echo '<td class="remove-itm"><a class="btn btn-danger" href="cart_update.php?removep='.$cart_itm["id"].'&return_url='.$current_url.'">Delete   <span class="glyphicon glyphicon-trash"></span></a></td>';
        
        echo '</tr>';
        $total = ($total + $subtotal);
        echo '<input type="hidden" name="item_name['.$cart_items.']" value="'.$obj->name.'" />';
        echo '<input type="hidden" name="item_code['.$cart_items.']" value="'.$product_id.'" />';
        echo '<input type="hidden" name="item_desc['.$cart_items.']" value="'.$obj->description.'" />';
        echo '<input type="hidden" name="item_qty['.$cart_items.']" value="'.$cart_itm["qty"].'" />';
        $cart_items ++;
    }
    // echo '</ol>';
    echo '</form>';
    echo '</table>';
    echo '<span class="check-out-txt"><strong>Total: '.$currency.$total.'</strong><pre> <a class="btn btn-success" href="check_out.php"><span class="glyphicon glyphicon-shopping-cart" ></span> Check Out!</a> </span>';
    echo '<span class="empty-cart"><a class="btn btn-danger" href="cart_update.php?emptycart=1&return_url='.$current_url.'">Delete all products  <span class="glyphicon glyphicon-trash"></span></a></span></pre>';
}else{
    echo 'Empty Cart';
    echo '<meta http-equiv="refresh" content="2;URL= index.php">';
}
?>

</div>
</div>
</div>
</body>
<footer class="footer">
        <div><br><br>© DINH Thanh Hai - TRAN Duc Minh - KATAPI Baptista - BOUCHAMMACH Sofian - 3A STI INSA CVL</div>
</footer>
</html>