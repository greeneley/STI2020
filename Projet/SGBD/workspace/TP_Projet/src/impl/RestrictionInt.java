package impl;

import operateurs.Restriction;
import stockage.Nuplet;

import java.util.Vector;


public class RestrictionInt implements Restriction {

	@Override
	public Nuplet[] egalite(Nuplet[] t, int att, Object v) {
		// TODO Auto-generated method stub
		Vector<Nuplet> value = new Vector<Nuplet>();
		for(Nuplet n: t) {
			if((byte)(n.getAtt(att)) == (byte) v){
				value.addElement(n);
			}	
		}
		Nuplet[] ret = new Nuplet[value.size()];
		for(int i=0;i<value.size();i++)
			ret[i] = value.elementAt(i);
		return ret;
	}

	@Override
	public Nuplet[] superieur(Nuplet[] t, int att, Object v) {
		// TODO Auto-generated method stub
		Vector<Nuplet> value = new Vector<Nuplet>();
		for(Nuplet n: t) {
			if((byte)(n.getAtt(att)) > (byte) v){
				value.addElement(n);
			}	
		}
		Nuplet[] ret = new Nuplet[value.size()];
		for(int i=0;i<value.size();i++)
			ret[i] = value.elementAt(i);
		return ret;	}

	@Override
	public Nuplet[] inferieur(Nuplet[] t, int att, Object v) {
		// TODO Auto-generated method stub
		Vector<Nuplet> value = new Vector<Nuplet>();
		for(Nuplet n: t) {
			if((byte)(n.getAtt(att)) < (byte) v){
				value.addElement(n);
			}	
		}
		Nuplet[] ret = new Nuplet[value.size()];
		for(int i=0;i<value.size();i++)
			ret[i] = value.elementAt(i);
		return ret;
	}

}
