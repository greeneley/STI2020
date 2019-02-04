package TestObject;

public class Pair {
	private int first;
	private int second;
	public String toString() {
		return (super.toString()+" [" + first + "," + second + "]");
	}
	public int getFirst() {
		return first;
	}
	public void setFirst(int first) {
		this.first = first;
	}
	public int getSecond() {
		return second;
	}
	public void setSecond(int second) {
		this.second = second;
	}
	public Pair(int first, int second) {
		super();
		this.first = first;
		this.second = second;
	}
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + first;
		result = prime * result + second;
		return result;
	}
	// khi co cai ham equals nay roi, ta co the so sanh gia tri ma khong so dia chi vung nho anh huong den
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Pair other = (Pair) obj;
		if (first != other.first)
			return false;
		if (second != other.second)
			return false;
		return true;
	}
	
}
