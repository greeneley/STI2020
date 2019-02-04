package TestObject;

import java.util.HashMap;

import com.sun.javafx.collections.MappingChange.Map;

public class Catalogue {
	private HashMap<String, String> description;
	private Map<String, String> prix;
	public Catalogue(){
		description = new HashMap<String, String>();
		prix = new HashMap<String, Double>();
	}
	public void inserer(String ref, String desc, Double prix){
		this.description.put(ref,desc);
		this.prix.put(ref, prix);
	}
	public String getDescription(String ref){
		return description.get(ref,desc);
	}
	
}
