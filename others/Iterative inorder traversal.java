
public static class Node {
	int value;
	Node left, right;
}

public static void traverse(Node n) {
	Stack<Node> s = new Stack<>();
	addLeftToStack(s, n);

	while(!s.isEmpty()) {
		Node curr = s.pop();
		System.out.println(curr.value);
		if(curr.right != null){
			addLeftToStack(s, curr.right);
		}
	}
}

private static void addLeftToStack(Stack<Node> s, Node n) {
	while(n != null) {
		s.push(n);
		n = n.left;
	}
}