void bubble_sort(int *v, int n){
	int trocou = 1;
	int i;
	while (trocou == 1) {
		trocou = 0;
		for (i = 0; i < n-1; i++){
			if (v[i] > v[i+1]){
				int aux = v[i];
				v[i] = v[i+1];
				v[i+1]=aux;
				trocou = 1;				
			}
		}
	}
}

void selection_sort(int *v, int n){
	int pos_min, aux = 0;
	int i, j;
	for (i = 0; i < n-1; i++){
		pos_min = i;
		for (j = i+1; j < n; j++) {
			if (v[j] < v[pos_min]){
				pos_min = j;
			}
		}
		aux = v[pos_min];
		v[pos_min] = v[i];
		v[i] = aux;
	}
}

void insertion_sort(int *v, int n){
	int i = 0, j = 0;
	int aux = 0;
	for (j = 2; j< n; j++){
		aux = v[j];
		i = j - 1;
		while (i >= 0 && v[i] > aux){
			v[i + 1] = v[i];
			i = i - 1;
		}
		v[i + 1] = aux;
	}
}

int partion(int *v, int inicio, int fim){
	int x = v[fim];
	int i = inicio - 1;
	int aux = 0, j;
	
	for (j = inicio; j < fim; j++){
		if(v[j]<= x){
			i = i + 1;
			aux = v[i];
			v[i] = v[j];
			v[j] = aux;
		}
	}
	
	aux = v[i + 1];
	v[i + 1] = v[fim];
	v[fim] = aux;
	
	return i + 1;
}

void quick_sort(int *v, int inicio, int fim){
	if (inicio < fim){
		int q = partion(v, inicio, fim);
		quick_sort(v, inicio, q - 1);
		quick_sort(v, q + 1, fim);
	}
}

void merge(int *v, int inicio, int meio, int fim){
	int n1 = meio - inicio + 1;
	int n2 = fim - meio;
	int aux, i, j, k;
	
	int L[n1], R[n2];
	
	for (aux = 0; aux < n1; aux++) {
		L[aux] = v[inicio + aux];
	}
       
    for (aux = 0; aux < n2; aux++) {
    	R[aux] = v[meio + 1 + aux];
	}
	
	i = 0, j = 0, k = inicio;
	
	while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            v[k] = L[i];
            i++;
        }
        else {
            v[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        v[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        v[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int *v, int inicio, int fim){
	if (inicio < fim) {
        int q = inicio + (fim - inicio) / 2;
        merge_sort(v, inicio, q);
        merge_sort(v, q + 1, fim);
        merge(v, inicio, q, fim);
    }
}