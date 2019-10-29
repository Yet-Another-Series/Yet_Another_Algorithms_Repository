import java.util.Queue;
import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;


public class TreeTopView {
	static Scanner scn = new Scanner(System.in);

	private class Node {
		int data;
		Node left;
		Node right;

	}

	private Node root;

	public TreeTopView() {
		root = takeInput();
	}

	private Node takeInput() {
		int RootData = scn.nextInt();
		if (RootData == -1) {
			return null;
		}
		Node rootNode = new Node();
		rootNode.data = RootData;

		Queue<Node> queue = new java.util.LinkedList<>();
		queue.add(rootNode);

		while (!queue.isEmpty()) {
			Node fn = queue.remove();

			int ld = scn.nextInt();
			if (ld != -1) {
				Node ln = new Node();
				ln.data = ld;
				fn.left = ln;
				queue.add(ln);
			}

			int rd = scn.nextInt();
			if (rd != -1) {
				Node rn = new Node();
				rn.data = rd;
				fn.right = rn;
				queue.add(rn);
			}

		}

		return rootNode;
	}

	private class VOPair implements Comparable<VOPair> {
		int data;
		int vl;
		int hl;

		public VOPair(int data, int hl, int vl) {
			this.data = data;
			this.hl = hl;
			this.vl = vl;
		}

		@Override
		public int compareTo(VOPair o) {

			return this.hl - o.hl;
		}

		@Override
		public String toString() {

			return this.data + "";
		}
	}

	public void verticaldisplay() {
		HashMap<Integer, ArrayList<VOPair>> map = new HashMap<>();

		verticalDisp(root, map, 0, 0);

		ArrayList<Integer> allkeys = new ArrayList<>(map.keySet());
		Collections.sort(allkeys);

		for (int key : allkeys) {
			ArrayList<VOPair> list = map.get(key);
			Collections.sort(list);
			System.out.print(list.get(0)+" ");
		}

	}

	private void verticalDisp(Node node, HashMap<Integer, ArrayList<VOPair>> map, int hl, int vl) {
		if (node == null) {
			return;
		}

		if (!map.containsKey(vl)) {
			map.put(vl, new ArrayList<>());
		}

		ArrayList<VOPair> arr = map.get(vl);
		VOPair np = new VOPair(node.data, hl, vl);
		arr.add(np);

		verticalDisp(node.left, map, hl + 1, vl - 1);
		verticalDisp(node.right, map, hl + 1, vl + 1);
	}



	public static void main(String[] args) {
		TreeTopView bt = new TreeTopView();
		bt.verticaldisplay();
		

	}

}

