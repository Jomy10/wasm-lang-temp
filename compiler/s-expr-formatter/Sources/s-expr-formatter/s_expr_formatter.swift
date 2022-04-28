import Foundation

/// A simple S-expression formatter
///
/// The formatter only fixes indentation
public func __format(input: String, tab: String = "    ") -> String {
    var tabs = 0
    return input.split(separator: "\n").map { s in
        let _s = s.trimmingCharacters(in: .whitespacesAndNewlines)

        var openedParan = 0
        _s.forEach { char in
            if char == "(" {
                openedParan += 1
            } else if char == ")" {
                openedParan -= 1
            }
        }

        if openedParan < 0 { tabs += openedParan }

        let newString =  String(repeating: tab, count: tabs) + _s

        if openedParan > 0 { tabs += openedParan }

        return newString

    }.joined(separator: "\n")
}

/// C bridge function for `__format`
@_cdecl("format")
public func format(input: UnsafePointer<CChar>, tab: UnsafePointer<CChar>) -> UnsafePointer<CChar>? {
    let _input = String(cString: input)
    let _tab = String(cString: tab)
    let s = __format(
        input: _input,
        tab: _tab
    )
    let newStr = strdup(s)
    return UnsafePointer(newStr)
}

/// free UnsafePointer
@_cdecl("free_format")
public func free_format(inp: UnsafePointer<CChar>) {
    inp.deallocate()
}
