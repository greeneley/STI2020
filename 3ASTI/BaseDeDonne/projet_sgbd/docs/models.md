# Modélisation
Il existe dans le code plusieurs entité permettant de représenter des conteneurs de données

## Relation
Une relation est un tableau dans lequel on peut range des tuples.  
Pour la construire il faut sépcifier combien de colonnes la relation devra gérer et le nom qu'elle aura.  

## Tuple
Un tuple est un tableau de n colonnes, il sert de conteneur pour les lignes d'une relation, n vaut donc le nombre de colonnes demandé à l'initialisation de la relation. Pour avoir le choix de remplir le tuple tranquillement ou bien dès la déclaration, plusieurs constructeurs sont fournis.

```java
public class main {
    public static void main(String[] args) {
        System.out.println("On creer le tuple 'tranquille':");
        Tuple tranquille = new Tuple(3);
        tranquille.changeValue(0, 1);
        tranquille.changeValue(1, 2);
        tranquille.changeValue(2, 5);

        System.out.println("On creer le tuple 'direct':");
        Tuple direct = new Tuple(3, new int[]{1,2,6});

        // On peut aussi activer le mode debug pour savoir ce qui se passe.
        System.out.println("On creer le tuple 'tranquilleDebug':");
        Tuple tranquilleDebug = new Tuple(3, true);
        tranquilleDebug.changeValue(0, 1);
        tranquilleDebug.changeValue(1, 2);
        tranquilleDebug.changeValue(2, 5);

        System.out.println("On creer le tuple 'directDebug':");
        Tuple directDebug = new Tuple(3, new int[]{1,2,6}, true);
    }
}
```

## Exemple

```java
public class main {
    public static void main(String[] args) {
        Relation rel = new Relation("test", 3, true); // true permet de passer en mode debug
        System.out.println(rel);

        rel.insert(new Tuple(3, new int[]{1,4,5}, true));
        rel.insert(new Tuple(3, new int[]{5,7,4}, true));
        rel.insert(new Tuple(3, new int[]{25,12,8}, true));
        System.out.println(rel);
    }
}
```
