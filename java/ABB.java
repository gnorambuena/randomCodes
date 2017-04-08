import java.util.Queue;
import java.util.LinkedList;
public class ABB implements ArbolBinario {
	Nodo root;
	ABB(int n){
		root=new Nodo(n); 
	}
	public void insertar(int x) {
		Nodo aux=root;
		while(aux!=null){
			if(x>aux.val){
				if(aux.right==null){
					aux.right=new Nodo(x);
					break;
				}
				aux=aux.right;
			}
			else{
				if(aux.left==null){
					aux.left=new Nodo(x);
					break;
				}
				aux=aux.left;
			}
		}
	}
	public int height(Nodo n) {
		//basicamente un BFS para encontrar los nodos desde root
        if (n == null) {
            return 0;
        }
        Queue<Nodo> q = new LinkedList();
        q.add(n);
        int altura = 0;
        while (q.size()!=0) {
            int cont = q.size();
            altura++;
            while (cont > 0) {
                Nodo aux = q.peek();
                q.remove();
                if (aux.right != null) {
                    q.add(aux.right);
                }
                if (aux.left != null) {
                    q.add(aux.left);
                }
                cont--;
            }
        }
        return altura;
	}
	public boolean buscar(int x) {
		Nodo aux=root;
		while(aux!=null){
			if(x==aux.val)break;
			else if(x>aux.val)aux=aux.right;
			else aux=aux.left;
		}
		return aux!=null;
	}
	private void lprint(Nodo aux){
		if(aux==null)return;
		lprint(aux.left);
		System.out.println(aux.val);
		lprint(aux.right);
	}
	public void print(){
		lprint(root);
	}
	public int altura(){
		return height(root);
	}
}
