import 'list_integer.dart';

class Cardinalidade {
  List<ListInteger> l = [];
  List<int> soma = [];
  List<String> strCard = [];
  List<String> str = ["A", "B", "C", "D", "E", "F", "G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"];

  void addListInteger(ListInteger card) {
    l.add(card);
  }

  List<List<Object>> getMatriz(int index) {
    return l[index].getCard();
  }

  void calcCardinalidade() {
    for (int k = 1; k <= l.length; k++) {
      List<int> indices = [];
      for (int i = 0; i < k; i++) {
        indices.add(i);
      }
      for (int m = indices[0]; m <= l.length - k;) {
        List<ListInteger> b = [];
        for (int n = 0; n < k; n++) {
          b.add(l[indices[n]]);
        }
        somaCardinalidade(b, indices);
        indices[indices.length - 1]++;
        if (k == l.length) {
          break;
        }

        if (indices[indices.length - 1] >= l.length) {
          indices = novoIndice(indices, indices.length - 1, l.length, 1);
        }
        m = indices[0];
      }
    }
    print(soma);
    print(soma.reduce((value, element) => value + element));
  }

  List<int> novoIndice(
      List<int> indices, int index, int lLenght, int profundidade) {
    if (index - 1 < 0) {
      return indices;
    }
    indices[index - 1]++;
    indices[index] = indices[index - 1] + 1;
    if (indices[index - 1] + profundidade >= lLenght) {
      indices = novoIndice(indices, index - 1, lLenght, profundidade + 1);
      indices[index] = indices[index - 1] + 1;
    }
    return indices;
  }

  void somaCardinalidade(List<ListInteger> b, List<int> indices) {
    soma.add(0);
    strCard.add(addStrCard(indices));
    for (int i = 0; i < b[0].m[0].length; i++) {
      if (b[0].m[1][i] as bool == false) {
        continue;
      }
      if (searchInteger(b[0].m[0][i] as int, 1, b)) {
        soma[soma.length - 1]++;
      }
    }
    if (indices.length % 2 == 0) {
      soma[soma.length - 1] = -soma[soma.length - 1];
    }
    print("negativo ou positivo = ${indices.length}");
    print("str: ${strCard[strCard.length - 1]}");
    print("soma: ${soma[soma.length - 1]}");
  }

  bool searchInteger(int n, int index, List<ListInteger> b) {
    if (index >= b.length) {
      //print("achou $n");
      return true;
    }
    for (int i = 0; i < b[index].m[0].length; i++) {
      if (b[index].m[0][i] as int == n) {
        return searchInteger(n, index + 1, b);
      }
    }
    return false;
  }

  String addStrCard(List<int> indices) {
    String str = "n(";
    for (int i = 0; i < indices.length; i++) {
      str = "$str${this.str[indices[i]]}∩";
    }
    str = "${str.substring(0, str.length - 1)})";
    return str;
  }
}
