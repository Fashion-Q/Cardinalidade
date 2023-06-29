import 'cardinalidade.dart';
import 'list_integer.dart';

void main(List<String> arguments) {
  Cardinalidade l = Cardinalidade();
  List<List<int>> a = [];
  a.add([1, 7, 11, 2, 5, 8, 5, 5]);
  a.add([1, 2, 4, 18, 5, 11, 6]);
  a.add([18, 19, 1, 2, 7]);
  a.add([1, 3, 8, 10]);
  a.add([1, 1, 1, 1]);
  a.add([1, 1, 1, 1, 3, 5]);
  a.add([1, 1, 1, 3, 5]);
  // a.add([11, 1, 3, 5]);
  // a.add([3, 5, 7, 9]);
  for (int i = 0; i < a.length; i++) {
    l.addListInteger(ListInteger(vetor: a[i]));
  }
  // for (int i = 0; i < 10; i++) {
  //   l.addListInteger(ListInteger(vetor: null));
  // }
  for (int i = 0; i < l.l.length; i++) {
    print(l.l[i].m[0]);
    print(l.l[i].m[1]);
  }
  l.calcCardinalidade();
}
