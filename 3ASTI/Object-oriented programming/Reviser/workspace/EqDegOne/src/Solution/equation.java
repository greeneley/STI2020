package Solution;

public class equation {
	public float  a;
	public float  b;
	boolean solved;
	public float solution;
	float getA(float a){
		return this.a;
	}
	float getB(float b){
		return this.b;
	}
	public equation(float unA,float unB){
		System.out.println("In gia tri ra");
		this.a=unA;
		this.b=unB;
	}
	public float solve(){
		if(a==0){
			System.out.println("error");
			return 0;
		}
		else
			return -this.getA(a)/this.getB(b);
	}
}
