import 'dart:math';

class ListInteger {
  List<List<Object>> m = [];

  ListInteger({List<int>? vetor}) {
    m = vetor == null ? getRandomCard() : addBoo(vetor);
  }

  List<int> getVetor() {
    return m[0] as List<int>;
  }

  List<List<Object>> getCard() {
    return m;
  }

  List<List<Object>> addBoo(List<int> vetor) {
    m.add([]);
    m.add([]);
    m[0] = vetor;
    m[1] = List<bool>.filled(m[0].length, true);
    fixBoo(m);
    return m;
  }

  List<List<Object>> getRandomCard() {
    List<List<Object>> card = [];
    card.add([]);
    card.add([]);
    card[0] = randomListInteger();
    card[1] = List<bool>.filled(card[0].length, true);
    fixBoo(card);
    return card;
  }

  void fixBoo(List<List<Object>> t) {
    for (int i = 0; i < t[0].length; i++) {
      for (int j = i + 1; j < t[0].length; j++) {
        if (t[0][i] == t[0][j]) {
          t[1][j] = false;
        }
      }
    }
  }

  List<int> randomListInteger() {
    List<int> integer = [];
    for (int i = 0;
        i < Random().nextInt(8) + 3;
        i++, integer.add(Random().nextInt(20) + 1)) {}
    return integer;
  }
}
