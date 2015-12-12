Pod::Spec.new do |s|
  s.name             = "FlashPollsSDK"
  s.version          = "0.1.0"
  s.summary          = "Conduct flash polls using interactive push notifications."

  s.description      = <<-DESC
    "Conduct flash polls using interactive push notifications."
                       DESC

  s.homepage         = "https://github.com/YoApp/FlashPollsSDK"
  # s.screenshots     = "www.example.com/screenshots_1", "www.example.com/screenshots_2"
  s.license          = 'MIT'
  s.author           = { "Life Before Us, Inc" => "contact@justyo.co" }
  s.source           = { :git => "https://github.com/YoApp/FlashPollsSDK.git", :tag => s.version.to_s }
  s.social_media_url = 'https://twitter.com/FlashPollsApp'

  s.platform     = :ios, '8.0'
  s.requires_arc = true

  s.source_files = 'Pod/Classes/**/*'
  s.resource_bundles = {
    'FlashPollsSDK' => ['Pod/Assets/*.png']
  }

  # s.public_header_files = 'Pod/Classes/**/*.h'
  # s.frameworks = 'UIKit', 'MapKit'
  # s.dependency 'AFNetworking', '~> 2.3'
end
