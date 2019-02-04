<?php
session_start(); 
include_once("config.php"); //include config file
 
//DESTROY cart
if(isset($_GET["emptycart"]) && $_GET["emptycart"]==1)
{
    $return_url = base64_decode($_GET["return_url"]); //return url
    session_destroy();
    header('Location:'.$return_url);
}
 
//add to cart
if(isset($_POST["type"]) && $_POST["type"]=='add')
{
    $product_id   = filter_var($_POST["product_id"], FILTER_SANITIZE_STRING); //product id
    $product_qty  = filter_var($_POST["product_qty"], FILTER_SANITIZE_NUMBER_INT); //quantity
    $return_url   = base64_decode($_POST["return_url"]); // url trả về
    
    $results = $mysqli->query("SELECT name, price FROM product WHERE product_id='$product_id' LIMIT 1");
    $obj = $results->fetch_object();
    
    if ($results) { 
        $new_product = array(array('name'=>$obj->name, 'id'=>$product_id, 'qty'=>$product_qty, 'price'=>$obj->price));
        
        if(isset($_SESSION["products"]))
        {
            $found = false; 
            
            foreach ($_SESSION["products"] as $cart_itm) 
            {
                if($cart_itm["id"] == $product_id){ 
 
                    $product[] = array('name'=>$cart_itm["name"], 'id'=>$cart_itm["id"], 'qty'=>$product_qty, 'price'=>$cart_itm["price"]);
                    $found = true;
                }else{
                    $product[] = array('name'=>$cart_itm["name"], 'id'=>$cart_itm["id"], 'qty'=>$cart_itm["qty"], 'price'=>$cart_itm["price"]);
                }
            }
            
            if($found == false) 
            {
                $_SESSION["products"] = array_merge($product, $new_product);
            }else{
                $_SESSION["products"] = $product;
            }
            
        }else{
            $_SESSION["products"] = $new_product;
        }
        
    }
  header('Location:'.$return_url);
}
 
if(isset($_GET["removep"]) && isset($_GET["return_url"]) && isset($_SESSION["products"]))
{
    $product_id   = $_GET["removep"]; 
    $return_url     = base64_decode($_GET["return_url"]); 
 
    
    foreach ($_SESSION["products"] as $cart_itm) 
    {
        if($cart_itm["id"]!=$product_id){ 
            $product[] = array('name'=>$cart_itm["name"], 'id'=>$cart_itm["id"], 'qty'=>$cart_itm["qty"], 'price'=>$cart_itm["price"]);
        }
           $_SESSION["products"] = $product;
    }
    
    header('Location:'.$return_url);
}