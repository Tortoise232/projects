package repository;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by Petean Mihai on 1/3/2017.
 */
public class InMemoryRepository<T> implements IRepository<T> {
    protected List<T> data;

    public InMemoryRepository() {
        this.data = new ArrayList<T>();
    }

    public InMemoryRepository(List<T> data){
        this.data = data;
    }

    @Override
    public void addObject(T object) {
        data.add(object);
    }

    @Override
    public List<T> getData() {
        return this.data;
    }

    @Override
    public void setData(List<T> data) {
        this.data = data;
    }

    @Override
    public int getSize() {
        return this.data.size();
    }

    @Override
    public Object removeObject(Object object) {
        data.remove(object);
        return object;
    }

}
