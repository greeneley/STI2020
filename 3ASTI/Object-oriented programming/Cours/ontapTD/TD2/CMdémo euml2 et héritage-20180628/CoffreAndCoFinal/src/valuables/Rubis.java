/**
 * 
 */
package valuables;

/** 
 * @author pascal
 */
public class Rubis extends Gemstone {

	/**
	 * @param weight
	 * @param volume
	 */
	public Rubis(double weight, double volume) {
		super(weight, volume);
		// TODO Auto-generated constructor stub
	}

	@Override
	public void expertize() {
		// TODO Auto-generated method stub
		value = volume * volume * weight;
	}

}
