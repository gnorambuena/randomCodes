class A {
void bar() { this.foo(); }
private void foo() { System.out.println("A.foo()"); }
}
class B extends A {
void foo() { System.out.println("B.foo()"); }
public static void main(String[] argv) {
new B().bar();
}
}