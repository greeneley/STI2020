// package model;

import java.util.*;

public class Relation {
    public ArrayList<Tuple> relations = new ArrayList<Tuple>();
    private int colAmount = 0;
    private String name = null;
    private boolean debug = false;

    public Relation(String name, int columnAmount) {
        this.relations = new ArrayList<Tuple>();
        this.colAmount = columnAmount;
        this.name = name;
    }

    public Relation(String name, int columnAmount, boolean debug) {
        this(name, columnAmount);
        this.debug = debug;
        this.printDebug("Je suis en train de créer la table de relation");
    }

    private void printDebug(String string) {
        // TODO: A améliorer pour fonctionner comme println
        if (this.debug)
            System.out.println(string);
    }

    public String toString() {
        return (
            "nom de la table: " + this.name +
            " ayant " + this.colAmount + " colonnes et " +
            this.relations.size() + " lignes"
        );
    }

    public int getSize() {
        return this.relations.size();
    }

    public void add(Tuple new_line) {
        System.out.println("Adding a line to the relation");
        this.relations.add(new_line);
    }

    public int getColumnAmount() {
        return this.colAmount;
    }

    public static void printRelation(Relation rel){
        System.out.println("====================");
        System.out.println(rel);
        for (int i=0; i < rel.getSize(); i++) {
            System.out.print("La ligne numéro " + i + " a pour valeurs:");
            Tuple ligne = rel.relations.get(i);
            for (int j=0; j < ligne.getLength(); j++) {
                System.out.print(" " + ligne.getColumnValue(j));
            }
            System.out.println(";");
        }
        System.out.println("====================");
    }
}
