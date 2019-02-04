package impl;

import java.util.HashMap;
import java.util.Vector;

import operateurs.Jointure;
import stockage.Nuplet;

public class JointureH implements Jointure {
	
	public Nuplet joinTwoNuplet(Nuplet n1, Nuplet n2, int mergeAttribute) {
        NupletInt merged = new NupletInt(n1.size() + n2.size() - 1);

        for (int i = 0; i < n1.size(); i++)
            merged.putAtt(i, n1.getAtt(i));
        for (int i = 0; i < mergeAttribute; i++)
            merged.putAtt(n1.size() + i, n2.getAtt(i));
        for (int i = mergeAttribute + 1; i < n2.size(); i++)
            merged.putAtt(n1.size() + i - 1, n2.getAtt(i));

        return merged;
    }
	@Override
	public Nuplet[] jointure(Nuplet[] t1, Nuplet[] t2, int att1, int att2) {
		// TODO Auto-generated method stub
		
		Vector<Nuplet> value = new Vector<Nuplet>();
		// Step 1: Hash phase
		HashMap<Object, Nuplet> hash = new HashMap<Object, Nuplet>();
		for (Nuplet n1 : t1) {
		    hash.put(n1.getAtt(att1), n1);
		}
		// Step 2: Join phase
		for (Nuplet n2: t2) {
			Nuplet hash_test = hash.get(n2.getAtt(att2));
			if(hash_test != null) {
				NupletInt tab = new NupletInt(hash_test.size() + n2.size() - 1);
				tab = (NupletInt) joinTwoNuplet(hash_test, n2, att2);
				value.addElement(tab);
			}
		}
		Nuplet[] ret = new Nuplet[value.size()];
		for(int i=0;i<value.size();i++)
			ret[i] = value.elementAt(i);
		return ret;
	}

}
