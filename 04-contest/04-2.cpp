template <class T, class Predicate>
T myfilter(const T arr, Predicate function)
{
    T arr_tmp{};
    for(auto it : arr) {
        if(function(it)){
            arr_tmp.insert(arr_tmp.end(), it);
        }
    }
    return arr_tmp;
}

