class LeftSequence:
  def fromList(_list, _tuple=[], length=0, started=False):
    if started:
      length -= 1
      _tuple[0] = _list[length],(_tuple[0])
      if length == 0:
        return tuple(_tuple)[0]
      else:
        return LeftSequence.fromList(_list, _tuple, length, True)
    else:
      if length == 0:
        return LeftSequence.fromList(_list, [(_list[len(_list)-1],())], len(_list)-1, True)

  def first(xs, _list, convertFromList=False):
    if convertFromList:
      return LeftSequence.fromList(_list)[0]
    return xs[0]
