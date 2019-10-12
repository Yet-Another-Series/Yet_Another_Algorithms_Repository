import sys
from functools import wraps
from copy import deepcopy


if sys.version_info[0] == 2:  # python 2
    def iteritems(dict):
        return dict.iteritems()
else:
    def iteritems(dict):
        return iter(dict.items())

def _hashable_wrap(func):
    @wraps(func, assigned=('__name__', '__doc__'))
    def new_func(self, *args, **kwargs):
        if getattr(self, '_hash', None) is not None:
            assert False, 'Cannot mutate HashableDict instance after the hash value is calculated'
        return func(self, *args, **kwargs)
    return new_func

class HashableDict(dict):
    def __hash__(self):
        result = getattr(self, '_hash', None)
        if result is None:
            result = 0
            for key, value in self.items():
                result ^= hash(key)
                result ^= hash(value)
            self._hash = result
        return result
    def __deepcopy__(self, memo):
        if getattr(self, '_hash', None) is not None:
            return self
        return HashableDict({deepcopy(key, memo): deepcopy(value, memo)
                            for key, value in iteritems(self)})
    __setitem__ = _hashable_wrap(dict.__setitem__)
    __delitem__ = _hashable_wrap(dict.__delitem__)
    clear = _hashable_wrap(dict.clear)
    pop = _hashable_wrap(dict.pop)
    popitem = _hashable_wrap(dict.popitem)
    setdefault = _hashable_wrap(dict.setdefault)
    update = _hashable_wrap(dict.update)
