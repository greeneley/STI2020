

I. CREATE DATABASE:

 1. create database: CREATE DATABASE commercial;
 2. In the 'commercial',
 CREATE TABLE `product` (
 `product_id` int(11) NOT NULL AUTO_INCREMENT,
 `name` varchar(255) DEFAULT NULL,
 `description` varchar(255) DEFAULT NULL,
 `image` varchar(255) DEFAULT NULL,
 `price` int(10) DEFAULT '0',
 `property` varchar(255) NOT NULL,
 `disponible` int(11) NOT NULL,
 PRIMARY KEY (`product_id`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8

  
REMARQUE: Dans ton ordinateur, pour connecter le database, tu as besoin de modifier :
  1. config.php
  
 $db_username = 'root'; 
$db_password = '______'; // mot de pass database ( par ex, dans mon ordinateur: root (thanhhai)
 
