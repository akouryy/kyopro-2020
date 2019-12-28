# Rustメモ

## 重要な言語仕様

シャドーイングあり
match式は各ケースの後に`,`が必要、複数文書くためには`{}`が必要
`..`はexclusive、`..=`がinclusive

## 入力



## よく使う型

### `!`
ボトム型 $`Nothing`

### `Option<T>`

* `o.unwrap()`: $`o.get`
* `o.expect(msg)`: $`o.getOrElse(panic(msg))`
