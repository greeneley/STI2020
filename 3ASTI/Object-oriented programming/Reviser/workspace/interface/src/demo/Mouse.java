package demo;
import demo.CanDrink;
import demo.CanEat;
public class Mouse extends Animal implements CanEat, CanDrink {

	@Override
	  public void back() {
	      System.out.println("Mouse back ...");
	  }
	 
	  @Override
	  public int getVelocity() {
	      return 85;
	  }
	 
	  @Override
	  public void drink() {
	      System.out.println("Mouse drink ...");
	  }
	 
	  @Override
	  public void eat() {
	      System.out.println("Mouse eat ...");
	  }
}
