public class Operators {
    public static Relation projection(Relation relation, int[] columnNum) {
        Relation projected_relation = new Relation("output", columnNum.length);
        for (Tuple old_line : relation.relations) {
            Tuple new_line = new Tuple(columnNum.length);
            for (int index : columnNum) {
                new_line.changeValue(index, old_line.getColumnValue(index));
            }
            projected_relation.add(new_line);
        }
        return projected_relation;
    }

    /**
    * Description:
    *   Pour etre utilisé, la méthode demande une relation, un tableau de numéro
    *   d'attributs et un tableau de numéro de valeur. La méthode va chercher
    *   à ne récupérer que les lignes pour lesquelles chaque
    *   tuple[attributeIndex[i]] == checkValue[i]
    */
    public static Relation restriction(Relation relation, int attributeIndex, int checkValue) {
        Relation restricted_relation = new Relation("output", relation.getColumnAmount());
        for (Tuple old_line : relation.relations) {
            if (old_line.getColumnValue(attributeIndex) == checkValue) {
                Tuple new_line = new Tuple(old_line.getLength());
                restricted_relation.add(new_line);
            }
        }
        return restricted_relation;
    }

    /**
    * Description:
    *   La jointure permet de fusionner deux tables selon un lien entre des
    *   colonnes de ces deux tables
    *   Pour etre utilisé vous devez passer deux tables (first_op et second_op)
    *   et deux numéro de colonnes pour la fusion (first_attr, second_attr).
    */
    public static Relation jointure(Relation first_op, Relation second_op, int first_attr, int second_attr) {
        int first_op_col = first_op.getColumnAmount();
        int second_op_col = second_op.getColumnAmount();
        int nb_col = first_op_col + second_op_col - 1;
        Relation joint_relation = new Relation("joint", nb_col);

        System.out.println("Joint on " + first_attr + " and " + second_attr);

        // Il faut trouver pour chaque ligne de la premiere table, les lignes
        // qui ont le meme attibut de jointure
        for (Tuple first_line : first_op.relations) {
            for (Tuple second_line : second_op.relations) {
                if (first_line.getColumnValue(first_attr) == second_line.getColumnValue(second_attr)) {
                    Tuple new_line = new Tuple(nb_col);
                    new_line.changeValue(0, first_line.getColumnValue(first_attr));
                    for (int i=0; i < first_line.getLength(); i++) {
                        if (i != first_attr) new_line.changeValue(i, first_line.getColumnValue(i));
                    }
                    for (int i=0; i < second_line.getLength(); i++) {
                        if (i != second_attr) new_line.changeValue(i, first_line.getColumnValue(i));
                    }
                    joint_relation.add(new_line);
                }
            }
        }
        return joint_relation;
    }
}
