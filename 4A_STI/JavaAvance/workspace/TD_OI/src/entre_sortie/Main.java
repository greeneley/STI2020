package entre_sortie;

import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.lang.reflect.Constructor;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.util.Collection;

import usine.ObjectProvider;

public class Main {

	public static void main(String[] args) throws NoSuchMethodException, SecurityException, InstantiationException, IllegalAccessException, IllegalArgumentException, InvocationTargetException, IOException {
		// TODO Auto-generated method stub
		ObjectProvider object = new ObjectProvider();
		Class myClass = object.getClass();
		// Exo 3: affichez les methodes publiques de la classe ObjectProvider
		Method m[] = myClass.getMethods(); // classe.getMethods() retourne une tableau Method[] object de type Classe
		for (int i = 0; i < m.length; i++) {
			System.out.println(m[i].getName()); // affichez le nom de methods
		}
		// Exo 4: Donnez les prototypes des methodes nommees
		Method giveMe = myClass.getMethod("giveMeIntegersAndStrings");
		System.out.println(giveMe);
		// getMethod("giveMeIntegersAndStrings") ca marche mais getMethod("storeSimilarObjects") ca va marcher pas
		// il faut parcourir des elements 
		for (int i = 0; i < m.length; i++) {
			if(m[i].getName() == "storeSimilarObjects") {
				System.out.println(m[i]);
			}
		}
		// Exo 5:Recuperez la collection d'object
		System.out.println("Exercice 5");
		Collection collection = object.giveMeIntegersAndStrings();
		for(Object obj: collection) {
			if ( obj instanceof String) System.out.println("String");
			else if ( obj instanceof Integer ) System.out.println("Integer");
			System.out.println("Exercice 6:");
			Class myClass1 = obj.getClass();
			try {
				Constructor construc = myClass1.getConstructor(null);
				Object test = construc.newInstance();
			} catch (NoSuchMethodException nsme) {
				nsme.printStackTrace();
			} catch (SecurityException se) {
				se.printStackTrace();
			} catch (InstantiationException e) {
				System.out.println("Ne pas avoir une instance de cette classe");
			} catch ( Exception e ) {
				e.printStackTrace();
			}
			System.out.println("Exercice 7: Recuperez les methods disponible de la collection");

//			test = myClass1.newInstance(); / classe.newInstance() : classe = object de type Class, newInstance elle fait appect au constructeurs par default (sans arguments)
			try {
				Class value = obj.getClass();
				Method byteValue_test = value.getMethod("byteValue");
			} catch (Exception e) {
				e.printStackTrace();
			}
		}
		System.out.println("================================");
		// Exercice 8
		// Su dung FileWriter and FileReader de luu lai
		System.out.println("Exercice 8");
		FileWriter outputStream = new FileWriter("output.txt");
		for (Object obj: collection) {
			System.out.println(obj);
			outputStream.write(str.charAt(obj));
		}
		outputStream.close();
	}

}
