package valuables;

import genericSafes.GenericSafe;
import genericSafes.IGemstore;
import safes.ToSale;


/**
 * @author  pascal
 * @version  1.0
 */
public abstract class Gemstone implements ToSale, IGemstore {
	
	/**
	 * @uml.property  name="value"
	 */
	protected double value;
	/**
	 * @uml.property  name="weight"
	 */
	protected final double weight;
	/**
	 * @uml.property  name="volume"
	 */
	protected final double volume;
	
	/**
	 * @param weight
	 * @param volume
	 */
	public Gemstone(double weight, double volume) {
		this.weight = weight;
		this.volume = volume;
		
		mySafe = null;
	}

	/**
	 * @return  the value
	 * @uml.property  name="value"
	 */
	public double getValue() {
		return value;
	}

	/**
	 * @return  the weight
	 * @uml.property  name="weight"
	 */
	public double getWeight() {
		return weight;
	}

	/**
	 * @return  the volume
	 * @uml.property  name="volume"
	 */
	public double getVolume() {
		return volume;
	}
	
	
	public abstract void expertize();
	/*
	{
		value = weight * volume * Math.PI;
	}
	*/
	
	
	// Connection with a safe
	/**
	 * @uml.property  name="mySafe"
	 * @uml.associationEnd  
	 */
	private GenericSafe<Integer> mySafe;

	/**
	 * @return  the mySafe
	 * @uml.property  name="mySafe"
	 */
	public GenericSafe<Integer> getMySafe() {
		return mySafe;
	}

	/**
	 * @param mySafe  the mySafe to set
	 * @uml.property  name="mySafe"
	 */
	public void setMySafe(GenericSafe<Integer> mySafe) {
		this.mySafe = mySafe;
	}

}
