# fftw

Self hosted fftw library converted to Pod (http://fftw.org/)

## Development Instructions

We use [Bundler](https://bundler.io) to create a virtual environment for iOS dependencies (such as [Cocoapods](https://cocoapods.org) and [Fastlane](https://fastlane.tools)) to ensure a consistent, predictable build environment for CI and local development.

Install Bundler using:
```
[sudo] gem install bundler
```

Install the Bundler dependencies specified in the `Gemfile` via:
```
bundle config set path vendor/bundle
bundle install
```

_These files are ignored in the .gitignore so it's important each dev does this on their own machine_

Finally, install the CocoaPod dependencies using Bundler:
```
bundle exec pod install
```

Open the `Example.xcworkspace` and you should be able to compile the example app and run the unit tests.

## Development Installation

Using CocoaPods you can add this framework to your framework and app `podspec` and `Podfile` like so using the appropriate version you'd like to check out (M.m.p = Major.minor.patch, see note on semantic versioning below):

### podspec (as a framework dependency)
```
spec.dependency 'GideonUtils', '~> M.m.p'
```

### Podfile

```
source 'git@github.com:gideon-health/ios-pods.git'

pod 'GideonUtils', '~> M.m.p'
```

### Setting up SwiftFormat (i.e. Auto Code Formatter)

We're using [SwiftFormat](https://github.com/nicklockwood/SwiftFormat) to ensure all the code for this repo is formatted uniformly across contributors. There is a pre-commit hook that will automatically format all code before pushing to github. You may have to set this up on your local machine's git setup via:
```bash
git config core.hooksPath .githooks
```  

Note: You must install the cocoapod dependencies first to make sure the SwiftFormat command line tool is installed locally.

After you've set this up you won't ever need to manually run SwiftFormat.


## Development Notes

[Cocoapods](https://cocoapods.org) are our preferred dependency management system for all internal iOS frameworks. Manually copying files, one-off static framework/library compilation, and other dependency management such as Carthage and Swift Package Manager are discouraged for now because we'd like to avoid internal dependency fragmentation between projects. Every developer should be able to jump into a new Gideon iOS project and know exactly how to install dependencies so they're not blocked working on features, fixes, etc.

If you're working on a framework in the context of an application, like in the Example app of each framework repo, it's important you add a `Run Script` to the application to properly retouch cocoapod framework dependencies so the source code for the specific changes you made are recompiled at each app run. This saves you from having to clean and recompile the CocoaPod dependencies each time you make a change in the framework source files. Here's what you want:

![cocoapod build script screenshot](https://res.cloudinary.com/drvibcm45/image/upload/v1575915446/Screen_Shot_2019-12-09_at_12.16.46_PM_jy0zvi.png)

Be sure to add this script BEFORE the `Embed Pods Frameworks` step.

```
# This step makes sures that changes to development pods
# are properly recompiled and reflected in each app run
find "${SRCROOT}/Pods" -type f -name *frameworks.sh -exec bash -c "touch \"{}\"" \;
```

## Releasing

To release a new version of this framework (via `Cocoapods`) you must do the following. Note that we'll be wrapping the `pod` commands with [bundler](https://bundler.io) (which is already configured in this repo) to ensure this guide is consistent regardless of what version of `Cocoapods` you have globally installed on your machine:

- Make sure the framework validates with Cocoapods:
```
bundle exec pod lib lint --sources=<gideon> --verbose --allow-warnings
```
_Note: We allow warnings, but you should read these and try to minimize any new ones you may have introduced. Also note that you must change `<gideon>` above with whatever you've named the [private spec repo for Gideon](https://github.com/gideon-health/ios-pods) to on your machine. If you haven't already done that then you can do it like so:_
```
bundle exec pod repo add gideon git@github.com:gideon-health/ios-pods.git
```

- Once it passes the validation you should bump the version in the `podspec`. Note that we use [semantic versioning](https://www.geeksforgeeks.org/introduction-semantic-versioning/). Make sure you bump the version appropriately, the goal is for others to be able to tell if and how this new version will break their app. A rule of thumb is that if you're just adding stuff you can do a minor version bump, but if you're changing APIs and know existing clients will not compile transparently then you must do a major version bump.

![](https://res.cloudinary.com/dplnvyrgn/image/upload/v1577656432/Semantic_Versioning_v7du4s.png)

- Once you modify the `podspec` push that change to master:
```
git add -A
git commit -m "Bumping version to M.m.p"
```

- Next tag a release that matches the version you specified in the `podspec`.
```
git tag M.m.p -m "A message with some release notes"
git push --tags
```

- Now you're ready to push a new release to our private specs repo. You can do that like so:
```
bundle exec pod repo push <gideon> --sources=<gideon>,cocoapods --verbose
```
_Note: You must change `<gideon>` above with whatever you've named the [private spec repo for Gideon](https://github.com/gideon-health/ios-pods) to on your machine._

🎉 Congrats you've released a version!
