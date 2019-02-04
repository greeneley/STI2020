package valuables;

import safes.Safe;



/**
 * 
 * @author pascal
 * @version 1.0
 */
public class Gemstone {
	
	private double value;
	private final double weight;
	private final double volume;
	
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
	 * @return the value
	 */
	public double getValue() {
		return value;
	}

	/**
	 * @return the weight
	 */
	public double getWeight() {
		return weight;
	}

	/**
	 * @return the volume
	 */
	public double getVolume() {
		return volume;
	}
	
	
	public void expertize(){
		value = weight * volume * Math.PI;
	}
	
	// Connection with a safe
	private Safe mySafe;

	/**
	 * @return the mySafe
	 */
	public Safe getMySafe() {
		return mySafe;
	}

	/**
	 * @param mySafe the mySafe to set
	 */
	public void setMySafe(Safe mySafe) {
		this.mySafe = mySafe;
	}

}
