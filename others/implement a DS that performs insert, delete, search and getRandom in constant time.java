/*implement a DS that performs insert, delete, search and getRandom in constant time */

public class MyDS {

	HashMap<Integer, Integer> hash;
	ArrayList<Integer> array;

	MyDs() {
		hash = new HashMap<Integer, Integer>();
		array = new ArrayList<Integer>();
	}

	public void insert(Integer data) {
		if(hash.containsKey(data)) return;

		array.add(data);

		hash.put(data, array.size() - 1);
	}

	public void remove(Integer data) {
		if(!hash.containsKey(data)) return;

		int index = hash.get(data);
		int size = array.size();

		Collections.swap(array, index, size-1);

		array.remove(size - 1);
		hash.remove(data);

		hash.put(data, array.get(index));
	}

	public Integer search(Integer data) {
		return hash.get(data);
	}

	public Integer getRandom() {
		Random random = new Random();

		int randIndex = random.nextInt(array.size() - 1);

		return array.get(randIndex);
	}
}