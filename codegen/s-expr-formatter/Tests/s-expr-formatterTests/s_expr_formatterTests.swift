import XCTest
@testable import s_expr_formatter

final class s_expr_formatterTests: XCTestCase {
    func testFormatter() {
        let expected =
        """
        (module
            (func $v
                (param $p i32)
                (result i32)
                local.get $p
            )
        )
        """

        let toFormat =
        """
                    (module
        (func $v
                (param $p i32)
        (result i32)
                local.get $p
        )
            )
        """

        let formatted = __format(input: toFormat)
        XCTAssertEqual(expected, formatted)
    }
}
