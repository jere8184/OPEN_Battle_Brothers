


namespace Utils
{
    template<typename T>
    int id_generator(int start_at = 0)
    {
        static int id = start_at;
        return ++id;
    }
}

