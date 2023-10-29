#include <vector>

namespace Data {
    template<typename T>
    class Array3d {
    private:
        int dim0; 
        int dim1; 
        int dim2; 
        std::vector<T> data; 

    public:
        
        Array3d(int dim0, int dim1, int dim2) : dim0(dim0), dim1(dim1), dim2(dim2) {
            data.resize(dim0 * dim1 * dim2); 
        }

        
        T& operator()(int i, int j, int k) {
            return data[i * dim1 * dim2 + j * dim2 + k];
        }

        
        std::vector<T> GetValues0(int i) {
            std::vector<T> slice(dim1 * dim2); 
            for (int j = 0; j < dim1; j++) {
                for (int k = 0; k < dim2; k++) {
                    slice[j * dim2 + k] = data[i * dim1 * dim2 + j * dim2 + k]; 
                }
            }
            return slice;
        }

      
        std::vector<T> GetValues1(int j) {
            std::vector<T> slice(dim0 * dim2); 
            for (int i = 0; i < dim0; i++) {
                for (int k = 0; k < dim2; k++) {
                    slice[i * dim2 + k] = data[i * dim1 * dim2 + j * dim2 + k]; 
                }
            }
            return slice;
        }

        
        std::vector<T> GetValues2(int k) {
            std::vector<T> slice(dim0 * dim1); 
            for (int i = 0; i < dim0; i++) {
                for (int j = 0; j < dim1; j++) {
                    slice[i * dim1 + j] = data[i * dim1 * dim2 + j * dim2 + k]; 
                }
            }
            return slice;
        }

        
        std::vector<T> GetValues01(int i, int j) {
            std::vector<T> slice(dim2); 
            for (int k = 0; k < dim2; k++) {
                slice[k] = data[i * dim1 * dim2 + j * dim2 + k]; 
            }
            return slice;
        }

        
        std::vector<T> GetValues02(int i, int k) {
            std::vector<T> slice(dim1); 
            for (int j = 0; j < dim1; j++) {
                slice[j] = data[i * dim1 * dim2 + j * dim2 + k]; 
            }
            return slice;
        }

        
        std::vector<T> GetValues12(int j, int k) {
            std::vector<T> slice(dim0);
            for (int i = 0; i < dim0; i++) {
                slice[i] = data[i * dim1 * dim2 + j * dim2 + k]; 
            }
            return slice;
        }

        
        void SetValues0(int i, std::vector<std::vector<T>> values) {
            for (int j = 0; j < dim1; j++) {
                for (int k = 0; k < dim2; k++) {
                    data[i * dim1 * dim2 + j * dim2 + k] = values[j][k]; 
                }
            }
        }
        
        void SetValues1(int j, std::vector<std::vector<T>> values) {
            for (int i = 0; i < dim0; i++) {
                for (int k = 0; k < dim2; k++) {
                    data[i * dim1 * dim2 + j * dim2 + k] = values[i][k]; 
                }
            }
        }

        
        void SetValues2(int k, std::vector<std::vector<T>> values) {
            for (int i = 0; i < dim0; i++) {
                for (int j = 0; j < dim1; j++) {
                    data[i * dim1 * dim2 + j * dim2 + k] = values[i][j]; 
                }
            }
        }

        
        void SetValues01(int i, int j, std::vector<std::vector<T>> values) {
            for (int k = 0; k < dim2; k++) {
                data[i * dim1 * dim2 + j * dim2 + k] = values[k]; 
            }
        }

        
        void SetValues02(int i, int k, std::vector<std::vector<T>> values) {
            for (int j = 0; j < dim1; j++) {
                data[i * dim1 * dim2 + j * dim2 + k] = values[j];
            }
        }

        
        void SetValues12(int j, int k, std::vector<std::vector<T>> values) {
            for (int i = 0; i < dim0; i++) {
                data[i * dim1 * dim2 + j * dim2 + k] = values[i]; 
            }
        }

        
        void ones() {
            for (int i = 0; i < dim0; i++) {
                for (int j = 0; j < dim1; j++) {
                    for (int k = 0; k < dim2; k++) {
                        data[i * dim1 * dim2 + j * dim2 + k] = 1; 
                    }
                }
            }
        }

        void zeros() {
            for (int i = 0; i < dim0; i++) {
                for (int j = 0; j < dim1; j++) {
                    for (int k = 0; k < dim2; k++) {
                        data[i * dim1 * dim2 + j * dim2 + k] = 0; 
                    }
                }
            }
        }

        void fill(T value) {
            for (int i = 0; i < dim0; i++) {
                for (int j = 0; j < dim1; j++) {
                    for (int k = 0; k < dim2; k++) {
                        data[i * dim1 * dim2 + j * dim2 + k] = value; 
                    }
                }
            }
        }

        
        void arrayPrint() {
            for (int i = 0; i < dim0; i++) {
                std::cout << "i = " << i << std::endl;
                for (int j = 0; j < dim1; j++) {
                    for (int k = 0; k < dim2; k++) {
                        std::cout << data[i * dim1 * dim2 + j * dim2 + k] << " "; 
                    }
                    std::cout << std::endl;
                }
                std::cout << std::endl;
            }
        }
    };
}