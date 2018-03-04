template <typename T>
class Iterator {
    virtual
    const T *const next() = 0;

    virtual
    bool has_next() = 0;
};
