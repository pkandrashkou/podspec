Pod::Spec.new do |s|
  s.name = 'FakeDocumentReader'
  s.version              = '0.0.5'
  s.homepage             = 'https://regula.com'
  s.license              = { type: 'commercial', text: <<-LICENSE
      © 2020 RegulaForensics. All rights reserved.
  LICENSE
    }
  s.authors             = { 'RegulaForensics' => 'support@regulaforensics.com' }
  s.summary             = 'This is a private cocoapods wrapper intended only for INTERNAL usage!'
  s.platform            = :ios, '9.0'
  s.source              = { http: 'https://pods.regulaforensics.com/RegulaCommon/doc-reader/0.0.5/FakeDocumentReader.xcframework.zip' }
  s.module_name         = 'FakeDocumentReader'
  s.vendored_frameworks = 'FakeDocumentReader.xcframework'
  s.dependency 'RegulaCommon'
end
