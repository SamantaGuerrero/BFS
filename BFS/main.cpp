#include <iostream>
#include <list>

using namespace std;

class Grafo{
	private:
		//Numero de vertices
		int V;
		//Puntero a lista de adyacencia
		list<int> *adj;
		
	public:
		//Constructor prototipo
		Grafo(int v);
		
		//Metodo para agregar un borde
		void addEdge(int v, int w);
		
		//Metodo para BFS para atravesar y dar un recurso "s"
		void BFS(int s); 	
};

//Constructor con numero de vertices
Grafo::Grafo(int v){
	//Coloca numero de vertices
	V = v;
	
	//Crea una nueva lista de adyacencia
	adj = new list<int>[v];
}

//Implementacion de metodo para agregar bordes
void Grafo::addEdge(int v, int w){
	adj[v].push_back(w);
}

//Realiza BFS dado un vertice inicial
void Grafo::BFS(int s){
	//Comienzo con  todos los vertices no visitados
	bool *visitado = new bool[V];
	for(int i = 0; i < V; i++){
		visitado[i] = false;
	}
	
	//Crear una cola para BFS
	list<int> queue;
	
	//Comienza vertice marcado como visita y agregar a cola
	visitado[s] = true;
	queue.push_back(s);
	
	//Continua hasta que la cola este vacia
	while(!queue.empty()){
		//Consigue
		s = queue.front();
		queue.pop_front();
		
	//Obtener todos los vertices adyacentes de ese vertice
	cout << "Comprobacion de vertices adyacentes para el vertice" << s << endl;
	for(auto i = adj[s].begin(); i != adj[s].end(); i++){ //AQUI HAY UN ERROR PORQUE MI COMPILADOR
														//NO RECONOCE auto COMO TIPO DE VARIABLE.
		
		//Solo importan los nodos no visitados
		if(!visitado[*i]){
			
			//Marcar como visitados
			cout << "Visitado y en cola" << *i <<endl;
			visitado[*i] = true;
			
			//Echa hacia atras para comprobar los vertices de ese vertice
			queue.push_back(*i);
			}
		}
	}
}


int main() {
	//Crea un nuevo Grafo
	Grafo g(6);
	
	//Crea algunos bordes para los vertices
	//Conexiones para el vector 0
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	
	//Conexiones para el vector 1
	g.addEdge(1, 0);
	g.addEdge(1, 3);
	g.addEdge(1, 4);
	
	//Conexiones para el vector 2
	g.addEdge(2, 0);
	g.addEdge(2, 4);
	
	//Conexiones para el vector 3
	g.addEdge(3, 1);
	g.addEdge(3, 4);
	g.addEdge(3, 5);
	
	//Conexiones para el vector 4
	g.addEdge(4, 1);
	g.addEdge(4, 2);
	g.addEdge(4, 3);
	g.addEdge(4, 5);
	
	//Conexiones para el vector 5
	g.addEdge(5, 3);
	g.addEdge(5, 4);
	
	//Realiza BFS e imprime resultado
	g.BFS(5);
	
	return 0;
}
