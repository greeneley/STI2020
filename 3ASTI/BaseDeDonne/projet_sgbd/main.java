public class main {
    public static void main(String[] args) {
        System.out.println("Bonjour");

        // Premiere table
        Relation rel = new Relation("test", 3);
        System.out.println(rel);
        Tuple first_line = new Tuple(3);
        first_line.changeValue(0, 2);
        rel.add(first_line);
        Tuple second_line = new Tuple(3);
        second_line.changeValue(1, 3);
        rel.add(second_line);
        Tuple third_line = new Tuple(3);
        third_line.changeValue(1, 3);
        third_line.changeValue(0, 2);
        rel.add(third_line);

        // Deuxieme table
        Tuple first_line2 = new Tuple(2);
        first_line2.changeValue(0, 2);
        Tuple second_line2 = new Tuple(2);
        second_line2.changeValue(1, 3);
        Relation rel2 = new Relation("test", 2);
        rel2.add(first_line2);
        rel2.add(second_line2);

        // Affichage
        Relation.printRelation(rel);
        Relation.printRelation(rel2);
        System.out.println("\n\n\n\n\n");

        // Test de la projection et de la restriction
        System.out.println("Testing projection");
        System.out.println(Operators.projection(rel, new int[]{0,1}));
        System.out.println("\n\n\n");
        System.out.println("Testing restriction");
        System.out.println(Operators.restriction(rel, 1, 3));
        System.out.println("\n\n\n");

        // Test de la jointure
        System.out.println(Operators.jointure(rel, rel2, 0, 1));
        Relation.printRelation(Operators.jointure(rel, rel2, 0, 1));

    }
}
