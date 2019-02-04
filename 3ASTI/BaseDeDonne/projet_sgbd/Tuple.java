// package model;

import java.util.Arrays;

/**
    Surcouche de modélisation, permet de représenter une ligne dans une table
    de relation.
*/
public class Tuple {

    private int[] array = null;
    private int columnAmount = 0;
    private boolean debug = false;

    public Tuple(int columnAmount) {
        this.array = new int[columnAmount];
        this.columnAmount = columnAmount;
    }

    public Tuple(int columnAmount, boolean debug) {
        this(columnAmount);
        this.debug = debug;
        this.printDebug("Creating a new tuple!");
    }

    public Tuple(int columnAmount, int[] values) throws ArrayStoreException {
        this(columnAmount);
        if (values.length > this.columnAmount) {
            throw new ArrayStoreException("too many values for the tuple");
        } else if (values.length < this.columnAmount) {
            throw new ArrayStoreException("too few values for the tuple");
        }
        this.array = values;
    }
    public Tuple(int columnAmount, int[] values, boolean debug) {
        this(columnAmount, values);
        this.debug = debug;
        this.printDebug("Creating a new tuple!");
    }

    private void printDebug(String string) {
        // TODO: A améliorer pour fonctionner comme println
        if (this.debug)
            System.out.println(string);
    }

    public String toString() {
        return Arrays.toString(this.array);
    }

    public void changeValue(int index, int value) {
        System.out.println("Changing index " + index + " with value " + value);
        array[index] = value;
    }

    public int getColumnValue(int index) {
        return this.array[index];
    }

    public int getLength(){
        return this.array.length;
    }
}
