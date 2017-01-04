package repository;

import java.util.List;

/**
 * Created by Petean Mihai on 1/3/2017.
 */
public interface IRepository<T> {
    void addObject(T object);
    void removeObject(T object);
    List<T> getData();
    void setData(List<T> data);
}
