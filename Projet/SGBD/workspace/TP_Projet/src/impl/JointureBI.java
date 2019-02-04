	package impl;

import java.util.Vector;

import operateurs.Jointure;
import stockage.Nuplet;

public class JointureBI implements Jointure {
	 public Nuplet joinTwoNuplet(Nuplet n1, Nuplet n2, int attributeMerge) {
	        NupletInt merged = new NupletInt(n1.size() + n2.size() - 1); 
	        for (int i = 0; i < n1.size(); i++)
	            merged.putAtt(i, n1.getAtt(i));
	        for (int i = 0; i < attributeMerge; i++)
	            merged.putAtt(n1.size() + i, n2.getAtt(i));
	        for (int i = attributeMerge + 1; i < n2.size(); i++)
	            merged.putAtt(n1.size() + i - 1, n2.getAtt(i));
	        return merged;
	    }
	@Override
	public Nuplet[] jointure(Nuplet[] t1, Nuplet[] t2, int att1, int att2) {
		// TODO Auto-generated method stub
		//		pseudo-code
		//		for each row R1 in the outer table
		//		   for each row R2 in the inner table
		//		      if R1.join_column = R2.join_column
		//		         return (R1, R2)		
		Vector<Nuplet> value = new Vector<Nuplet>();
		for(Nuplet n1: t1) {
			for(Nuplet n2: t2) {
				if((byte) n1.getAtt(att1) == (byte) n2.getAtt(att2)) {
					NupletInt tab = new NupletInt(n1.size() + n2.size() -1);
					tab = (NupletInt) joinTwoNuplet(n1, n2, att2);
					value.addElement(tab);
				}
			}
		}
		Nuplet[] ret = new Nuplet[value.size()];
		for(int i=0;i<value.size();i++)
			ret[i] = value.elementAt(i);
		return ret;
	}

}
